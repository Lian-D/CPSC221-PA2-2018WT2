/**
 * @file filler.cpp
 * Implementation of functions in the filler namespace. 
 *
 */
//#include "filler.h"

animation filler::fillStripeDFS(PNG& img, int x, int y, HSLAPixel fillColor,
                                int stripeSpacing, double tolerance, int frameFreq)
{
    stripeColorPicker sdfs(fillColor,stripeSpacing);
    return fill<Stack>(img,x,y,sdfs, tolerance,frameFreq);
    /**
     * @todo Your code here! 
     */
}

animation filler::fillBorderDFS(PNG& img, int x, int y,
                                    HSLAPixel borderColor, double tolerance, int frameFreq)
{
    HSLAPixel* center = img.getPixel(x,y);
    borderColorPicker bdfs(borderColor,img,tolerance,*center);
    return fill<Stack>(img,x,y,bdfs,tolerance,frameFreq);
    /**
     * @todo Your code here! 
     */
}

/* Given implementation of a DFS rainbow fill. */
animation filler::fillRainDFS(PNG& img, int x, int y,
                                    long double freq, double tolerance, int frameFreq)
{
    rainbowColorPicker a(freq);
    return fill<Stack>(img, x, y, a, tolerance, frameFreq);
}

animation filler::fillStripeBFS(PNG& img, int x, int y, HSLAPixel fillColor,
                                int stripeSpacing, double tolerance, int frameFreq)
{
    stripeColorPicker sbfs(fillColor,stripeSpacing);
    return fill<Queue>(img,x,y,sbfs,tolerance,frameFreq);
    /**
     * @todo Your code here! 
     */
}

animation filler::fillBorderBFS(PNG& img, int x, int y,
                                    HSLAPixel borderColor, double tolerance, int frameFreq)
{
    HSLAPixel* center = img.getPixel(x,y);
    borderColorPicker bbfs(borderColor,img,tolerance,*center);
    return fill<Queue>(img,x,y,bbfs,tolerance,frameFreq);
    /**
     * @todo Your code here! You should replace the following line with a
     */
}

/* Given implementation of a BFS rainbow fill. */
animation filler::fillRainBFS(PNG& img, int x, int y,
                                    long double freq, double tolerance, int frameFreq)
{
    rainbowColorPicker a(freq);
    return fill<Queue>(img, x, y, a, tolerance, frameFreq);
}

bool filler::checkTolerance(HSLAPixel* opixel, double tolerance,HSLAPixel* npixel){
    if(opixel->dist(*npixel) <= tolerance){
        return true;
    }
    else{
        return false;
    }
}

bool filler::findvector(vector<vector<int>> v1, vector<int> v2tofind){
    for(int i = 0; i < v1.size(); i++){
        if ((v1[i][0] == v2tofind[0]) && (v1[i][1] == v2tofind[1])){
            return true;
        }
    }
            return false;
    }

void filler::sendFrame(int k, int frameFreq, animation& ai,PNG& img){
    if(k % frameFreq == 0){
        ai.addFrame(img);
    }

}

template <template <class T> class OrderingStructure>
animation filler::fill(PNG& img, int x, int y, colorPicker& fillColor,
                       double tolerance, int frameFreq)
{
     int k = 0;
    animation ai;


    OrderingStructure<vector<int>> os;

    // OLD CODE IGNORE vector<vector<int>> pixelposyoinked;

    // 2d int array to store boolean values, a value is true if it has been processed, false if not
    int proc[img.width()][img.height()];

    proc[img.width()][img.height()] = true;

    cout << proc[img.width()][img.height()] << endl;

    // Initializes the processed array to be all false at the start
    for(int x = 0; x < img.width(); x++){
        for(int y = 0; y < img.height(); y++){
            proc[x][y] = false;
        }
    }


    // vector to store the center coordinates
    vector<int> firstxy;

    firstxy.push_back(x);
    firstxy.push_back(y);

    // changing the color of the pixel
    HSLAPixel* first = img.getPixel(x,y);
    HSLAPixel unchangedfirst = *first;
    *first = fillColor(x,y);
    //marking as processed
    proc[x][y] = true;
    // add to structure
    os.add(firstxy);
    // send frame if k is valid
    k++;
    sendFrame(k,frameFreq,ai,img);

    // OLD CODE IGNORE
    // vector<vector<int>> pixelposyoinked;

    // vector<int> yoink;
    // yoink.push_back(x);
    // yoink.push_back(y);

    // HSLAPixel* first = img.getPixel(yoink[0],yoink[1]);
    // *first = fillColor(yoink[0],yoink[1]);
    // pixelposyoinked.push_back(yoink);
    // os.add(yoink);
    // k++;
    // sendFrame(k,frameFreq,ai,img);

    // change centerf

    while(!os.isEmpty()){
        // this vector represents the pixel that is about to be removed from the structure
        vector<int> removepixelxy;
        
        removepixelxy = os.remove();


        // HSLAPixel* nyoinkp = img.getPixel(removepixelxy[0],removepixelxy[1]);

        // getting neighboring pixels
        HSLAPixel* upright = img.getPixel(removepixelxy[0]+1,removepixelxy[1]-1);

        vector<int> vupright;
        vupright.push_back(removepixelxy[0]+1);
        vupright.push_back(removepixelxy[1]-1); 

        HSLAPixel* up = img.getPixel(removepixelxy[0],removepixelxy[1]-1);

        vector<int> vup;
        vup.push_back(removepixelxy[0]);
        vup.push_back(removepixelxy[1]-1);

        
        HSLAPixel* upleft = img.getPixel(removepixelxy[0]-1,removepixelxy[1]-1);

        vector<int> vupleft;
        vupleft.push_back(removepixelxy[0]-1);
        vupleft.push_back(removepixelxy[1]-1);

        
        HSLAPixel* left = img.getPixel(removepixelxy[0]-1,removepixelxy[1]);

        vector<int> vleft;
        vleft.push_back(removepixelxy[0]-1);
        vleft.push_back(removepixelxy[1]);
        
        HSLAPixel* downleft = img.getPixel(removepixelxy[0]-1,removepixelxy[1]+1);

        vector<int> vdownleft;
        vdownleft.push_back(removepixelxy[0]-1);
        vdownleft.push_back(removepixelxy[1]+1);
        
        HSLAPixel* down = img.getPixel(removepixelxy[0],removepixelxy[1]+1);

        vector<int> vdown;
        vdown.push_back(removepixelxy[0]);
        vdown.push_back(removepixelxy[1]+1);
        
        HSLAPixel* downright = img.getPixel(removepixelxy[0]+1,removepixelxy[1]+1); 

        vector<int> vdownright;
        vdownright.push_back(removepixelxy[0]+1);
        vdownright.push_back(removepixelxy[1]+1);
        
        HSLAPixel* right = img.getPixel(removepixelxy[0]+1,removepixelxy[1]);

        vector<int> vright;
        vright.push_back(removepixelxy[0]+1);
        vright.push_back(removepixelxy[1]);


        // Here, check if the tolerance is valid and whether or not it has been processed yet, if both conditions are good
        // then change pixel color, add to structure, mark as processed, and check frames
        if(checkTolerance(unchangedfirst,tolerance,upright) && !(proc[vupright[0]][vupright[1]])){
            cout<< "adding neigbor" << endl;
            *upright = fillColor(vupright[0],vupright[1]);
            os.add(vupright);
            proc[vupright[0]][vupright[1]] = true;
            k++;
            sendFrame(k,frameFreq,ai,img);
        }

        if(checkTolerance(unchangedfirst,tolerance,up) && !(proc[vup[0]][vup[1]])){
            *up = fillColor(vup[0],vup[1]);
            os.add(vup);
            proc[vup[0]][vup[1]] = true;
             k++;
            sendFrame(k,frameFreq,ai,img);
        }

        if(checkTolerance(unchangedfirst,tolerance,upleft) && !(proc[vupleft[0]][vupleft[1]])){
            *upleft = fillColor(vupleft[0],vupleft[1]);
            os.add(vupleft);
            proc[vupleft[0]][vupleft[1]] = true;
             k++;
            sendFrame(k,frameFreq,ai,img);
        }

        if(checkTolerance(unchangedfirst,tolerance,left) && !(proc[vleft[0]][vleft[1]])){
            *left = fillColor(vleft[0],vleft[1]);
            os.add(vleft);
            proc[vleft[0]][vleft[1]] = true;
             k++;
            sendFrame(k,frameFreq,ai,img);
        }

        if(checkTolerance(unchangedfirst,tolerance,downleft) && !(proc[vdownleft[0]][vdownleft[1]])){
          *downleft = fillColor(vdownleft[0],vdownleft[1]);
          os.add(vdownleft);
           proc[vdownleft[0]][vdownleft[1]] = true;
           k++;
           sendFrame(k,frameFreq,ai,img); 
        }

        if(checkTolerance(unchangedfirst,tolerance,down) && !(proc[vdown[0]][vdown[1]])){
           *down =  fillColor(vdown[0],vdown[1]);
            os.add(vdown);
            proc[vdown[0]][vdown[1]];
             k++;
            sendFrame(k,frameFreq,ai,img);
        }

        if(checkTolerance(unchangedfirst,tolerance,downright) && !(proc[vdownright[0]][vdownright[1]])){
           *downright = fillColor(vdownright[0],vdownright[1]);
            os.add(vdownright);
            proc[vdownright[0]][vdownright[1]] = true;
             k++;
            sendFrame(k,frameFreq,ai,img);
        }

        if(checkTolerance(unchangedfirst,tolerance,right) && !(proc[vright[0]][vright[1]])){
            *right = fillColor(vright[0],vright[1]);
            os.add(vright);
            proc[vdownright[0]][vdownright[1]] = true;
             k++;
            sendFrame(k,frameFreq,ai,img);
        }
    }
    ai.addFrame(img);

    return ai;
 


    /**
     * @todo You need to implement this function!
     *
     * This is the basic description of a flood-fill algorithm: Every fill
     * algorithm requires an ordering structure, which is passed to this
     * function via its template parameter. For a breadth-first-search
     * fill, that structure is a Queue, for a depth-first-search, that
     * structure is a Stack. To begin the algorithm, you simply place the
     * given point in the ordering structure, marking it processed
     * (the way you mark it is a design decision you'll make yourself).
     * We have a choice to either change the color, if appropriate, when we
     * add the point to the OS, or when we take it off. In our test cases,
     * we have assumed that you will change the color when a point is added
     * to the structure. 
     *
     * Until the structure is empty, you do the following:
     *
     * 1.     Remove a point from the ordering structure, and then...
     *
     *        1.    add its unprocessed neighbors whose color values are 
     *              within (or equal to) tolerance distance from the center, 
     *              to the ordering structure.
     *        2.    use the colorPicker to set the new color of the point.
     *        3.    mark the point as processed.
     *        4.    if it is an appropriate frame, send the current PNG to the
     *              animation (as described below).
     *
     * 2.     When implementing your breadth-first-search and
     *        depth-first-search fills, you will need to explore neighboring
     *        pixels in some order.
     *
     *        For this assignment, each pixel p has 8 neighbors, consisting of 
     *        the 8 pixels who share an edge or corner with p. (We leave it to
     *        you to describe those 8 pixel locations, relative to the location
     *        of p.)
     *
     *        While the order in which you examine neighbors does not matter
     *        for a proper fill, you must use the same order as we do for
     *        your animations to come out like ours! 
     *
     *        The order you should put
     *        neighboring pixels **ONTO** the ordering structure (queue or stack) 
     *        is as follows: **UPRIGHT(+x,-y), UP(-y), UPLEFT(-x,-y), LEFT(-x), 
     *        DOWNLEFT(-x,+y), DOWN(+y), DOWNRIGHT(+x,+y), RIGHT(+x)**
     *
     *        If you do them in a different order, your fill may
     *        still work correctly, but your animations will be different
     *        from the grading scripts!
     *
     *        IMPORTANT NOTE: *UP*
     *        here means towards the top of the image, so since an image has
     *        smaller y coordinates at the top, this is in the *negative y*
     *        direction. Similarly, *DOWN* means in the *positive y*
     *        direction.  
     *
     * 3.     For every k pixels filled, **starting at the kth pixel**, you
     *        must add a frame to the animation, where k = frameFreq.
     *
     *        For example, if frameFreq is 4, then after the 4th pixel has
     *        been filled you should add a frame to the animation, then again
     *        after the 8th pixel, etc.  You must only add frames for the
     *        number of pixels that have been filled, not the number that
     *        have been checked. So if frameFreq is set to 1, a pixel should
     *        be filled every frame.
     * 4.     Finally, as you leave the function, send one last frame to the
     *        animation. This frame will be the final result of the fill, and 
     *        it will be the one we test against.
     */

} 

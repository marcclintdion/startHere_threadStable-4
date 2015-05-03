    if(rocks_o15_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &rocks_o15_COLORMAP); 
        rocks_o15_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(rocks_o15_VBO  != 0) 
    { 
        glDeleteBuffers(1, &rocks_o15_VBO); 
        rocks_o15_VBO  = 0; 
    } 
    if(rocks_o15_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &rocks_o15_INDICES_VBO); 
        rocks_o15_INDICES_VBO  = 0; 
    } 

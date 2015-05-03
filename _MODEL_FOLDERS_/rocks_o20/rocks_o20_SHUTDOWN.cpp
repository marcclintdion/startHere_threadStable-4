    if(rocks_o20_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &rocks_o20_COLORMAP); 
        rocks_o20_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(rocks_o20_VBO  != 0) 
    { 
        glDeleteBuffers(1, &rocks_o20_VBO); 
        rocks_o20_VBO  = 0; 
    } 
    if(rocks_o20_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &rocks_o20_INDICES_VBO); 
        rocks_o20_INDICES_VBO  = 0; 
    } 

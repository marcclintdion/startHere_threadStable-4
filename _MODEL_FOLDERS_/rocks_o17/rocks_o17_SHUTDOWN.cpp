    if(rocks_o17_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &rocks_o17_COLORMAP); 
        rocks_o17_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(rocks_o17_VBO  != 0) 
    { 
        glDeleteBuffers(1, &rocks_o17_VBO); 
        rocks_o17_VBO  = 0; 
    } 
    if(rocks_o17_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &rocks_o17_INDICES_VBO); 
        rocks_o17_INDICES_VBO  = 0; 
    } 

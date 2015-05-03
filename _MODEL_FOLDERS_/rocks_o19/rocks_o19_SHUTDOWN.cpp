    if(rocks_o19_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &rocks_o19_COLORMAP); 
        rocks_o19_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(rocks_o19_VBO  != 0) 
    { 
        glDeleteBuffers(1, &rocks_o19_VBO); 
        rocks_o19_VBO  = 0; 
    } 
    if(rocks_o19_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &rocks_o19_INDICES_VBO); 
        rocks_o19_INDICES_VBO  = 0; 
    } 

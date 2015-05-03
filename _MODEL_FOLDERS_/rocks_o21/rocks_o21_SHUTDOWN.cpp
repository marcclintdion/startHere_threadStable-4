    if(rocks_o21_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &rocks_o21_COLORMAP); 
        rocks_o21_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(rocks_o21_VBO  != 0) 
    { 
        glDeleteBuffers(1, &rocks_o21_VBO); 
        rocks_o21_VBO  = 0; 
    } 
    if(rocks_o21_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &rocks_o21_INDICES_VBO); 
        rocks_o21_INDICES_VBO  = 0; 
    } 

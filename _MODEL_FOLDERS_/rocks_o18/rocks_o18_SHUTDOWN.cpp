    if(rocks_o18_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &rocks_o18_COLORMAP); 
        rocks_o18_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(rocks_o18_VBO  != 0) 
    { 
        glDeleteBuffers(1, &rocks_o18_VBO); 
        rocks_o18_VBO  = 0; 
    } 
    if(rocks_o18_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &rocks_o18_INDICES_VBO); 
        rocks_o18_INDICES_VBO  = 0; 
    } 

    if(o10_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o10_COLORMAP); 
        o10_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o10_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o10_VBO); 
        o10_VBO  = 0; 
    } 
    if(o10_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o10_INDICES_VBO); 
        o10_INDICES_VBO  = 0; 
    } 

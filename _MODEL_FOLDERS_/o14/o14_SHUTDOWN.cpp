    if(o14_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o14_COLORMAP); 
        o14_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o14_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o14_VBO); 
        o14_VBO  = 0; 
    } 
    if(o14_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o14_INDICES_VBO); 
        o14_INDICES_VBO  = 0; 
    } 

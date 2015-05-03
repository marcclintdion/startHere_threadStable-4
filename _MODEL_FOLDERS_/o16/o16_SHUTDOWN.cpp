    if(o16_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o16_COLORMAP); 
        o16_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o16_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o16_VBO); 
        o16_VBO  = 0; 
    } 
    if(o16_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o16_INDICES_VBO); 
        o16_INDICES_VBO  = 0; 
    } 

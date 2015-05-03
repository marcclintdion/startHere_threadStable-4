    if(o20_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o20_COLORMAP); 
        o20_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o20_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o20_VBO); 
        o20_VBO  = 0; 
    } 
    if(o20_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o20_INDICES_VBO); 
        o20_INDICES_VBO  = 0; 
    } 

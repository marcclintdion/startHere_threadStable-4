    if(o11_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o11_COLORMAP); 
        o11_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o11_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o11_VBO); 
        o11_VBO  = 0; 
    } 
    if(o11_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o11_INDICES_VBO); 
        o11_INDICES_VBO  = 0; 
    } 

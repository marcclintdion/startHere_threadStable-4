    if(o19_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o19_COLORMAP); 
        o19_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o19_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o19_VBO); 
        o19_VBO  = 0; 
    } 
    if(o19_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o19_INDICES_VBO); 
        o19_INDICES_VBO  = 0; 
    } 

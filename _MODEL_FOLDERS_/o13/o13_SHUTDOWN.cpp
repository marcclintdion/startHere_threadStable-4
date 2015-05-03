    if(o13_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o13_COLORMAP); 
        o13_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o13_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o13_VBO); 
        o13_VBO  = 0; 
    } 
    if(o13_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o13_INDICES_VBO); 
        o13_INDICES_VBO  = 0; 
    } 

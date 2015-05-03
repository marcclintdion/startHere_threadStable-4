    if(o9_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o9_COLORMAP); 
        o9_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o9_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o9_VBO); 
        o9_VBO  = 0; 
    } 
    if(o9_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o9_INDICES_VBO); 
        o9_INDICES_VBO  = 0; 
    } 

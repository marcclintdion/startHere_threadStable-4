    if(o5_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o5_COLORMAP); 
        o5_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o5_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o5_VBO); 
        o5_VBO  = 0; 
    } 
    if(o5_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o5_INDICES_VBO); 
        o5_INDICES_VBO  = 0; 
    } 

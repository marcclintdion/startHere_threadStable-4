    if(o6_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o6_COLORMAP); 
        o6_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o6_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o6_VBO); 
        o6_VBO  = 0; 
    } 
    if(o6_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o6_INDICES_VBO); 
        o6_INDICES_VBO  = 0; 
    } 

    if(o1_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o1_COLORMAP); 
        o1_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o1_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o1_VBO); 
        o1_VBO  = 0; 
    } 
    if(o1_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o1_INDICES_VBO); 
        o1_INDICES_VBO  = 0; 
    } 

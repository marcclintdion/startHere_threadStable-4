    if(o2_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o2_COLORMAP); 
        o2_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o2_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o2_VBO); 
        o2_VBO  = 0; 
    } 
    if(o2_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o2_INDICES_VBO); 
        o2_INDICES_VBO  = 0; 
    } 

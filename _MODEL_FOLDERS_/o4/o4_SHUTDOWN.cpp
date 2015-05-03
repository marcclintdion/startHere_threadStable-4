    if(o4_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o4_COLORMAP); 
        o4_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o4_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o4_VBO); 
        o4_VBO  = 0; 
    } 
    if(o4_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o4_INDICES_VBO); 
        o4_INDICES_VBO  = 0; 
    } 

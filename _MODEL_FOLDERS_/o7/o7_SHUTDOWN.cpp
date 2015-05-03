    if(o7_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o7_COLORMAP); 
        o7_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o7_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o7_VBO); 
        o7_VBO  = 0; 
    } 
    if(o7_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o7_INDICES_VBO); 
        o7_INDICES_VBO  = 0; 
    } 

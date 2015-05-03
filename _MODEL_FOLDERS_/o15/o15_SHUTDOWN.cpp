    if(o15_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o15_COLORMAP); 
        o15_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o15_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o15_VBO); 
        o15_VBO  = 0; 
    } 
    if(o15_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o15_INDICES_VBO); 
        o15_INDICES_VBO  = 0; 
    } 

    if(o12_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o12_COLORMAP); 
        o12_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o12_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o12_VBO); 
        o12_VBO  = 0; 
    } 
    if(o12_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o12_INDICES_VBO); 
        o12_INDICES_VBO  = 0; 
    } 

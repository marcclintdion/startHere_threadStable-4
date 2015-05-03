    if(o21_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o21_COLORMAP); 
        o21_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o21_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o21_VBO); 
        o21_VBO  = 0; 
    } 
    if(o21_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o21_INDICES_VBO); 
        o21_INDICES_VBO  = 0; 
    } 

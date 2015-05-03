    if(o8_A_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o8_A_COLORMAP); 
        o8_A_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o8_A_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o8_A_VBO); 
        o8_A_VBO  = 0; 
    } 
    if(o8_A_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o8_A_INDICES_VBO); 
        o8_A_INDICES_VBO  = 0; 
    } 

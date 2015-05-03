    if(o8_B_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &o8_B_COLORMAP); 
        o8_B_COLORMAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(o8_B_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o8_B_VBO); 
        o8_B_VBO  = 0; 
    } 
    if(o8_B_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &o8_B_INDICES_VBO); 
        o8_B_INDICES_VBO  = 0; 
    } 

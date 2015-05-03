    if(deadForest_NORMALMAP != 0) 
    { 
        glDeleteTextures(1, &deadForest_NORMALMAP); 
        deadForest_NORMALMAP = 0; 
    } 
    if(deadForest_COLORMAP  != 0)
    { 
        glDeleteTextures(1, &deadForest_COLORMAP); 
        deadForest_COLORMAP  = 0; 
    } 
    if(deadForest_MASK0MAP  != 0)
    { 
        glDeleteTextures(1, &deadForest_MASK0MAP); 
        deadForest_MASK0MAP  = 0; 
    } 
    //-------------------------------------------------- 
    if(deadForest_VBO  != 0) 
    { 
        glDeleteBuffers(1, &deadForest_VBO); 
        deadForest_VBO  = 0; 
    } 
    if(deadForest_INDICES_VBO  != 0) 
    { 
        glDeleteBuffers(1, &deadForest_INDICES_VBO); 
        deadForest_INDICES_VBO  = 0; 
    } 

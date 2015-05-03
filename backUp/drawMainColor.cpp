//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    //=======================================================================================================================
    glClearColor( 0.05f, 0.075f, 0.25f, 1.0 );
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    //----------------------------------------------------------------------------------
    
    //=======================================================================================================================
    #ifdef WIN32
        //-------------------------------------------------------------------------------------------------------               
        glViewport(0, 0, (GLsizei)viewWidth, (GLsizei)viewHeight);
        LoadIdentity(projectionMatrix);
        PerspectiveMatrix(projectionMatrix, fieldOfView, (GLfloat)viewWidth / (GLfloat)viewHeight, adjustNearFar_CAMERA[0],  adjustNearFar_CAMERA[1]);
        //-------------------------------------------------------------------------------------------------------          
    #endif
    //=======================================================================================================================
    
    //=======================================================================================================================
    #ifdef __APPLE__
                            //__THE_+14_CORRECTS_FOR_DIFFERENCE_IN_iOS_vs._WINDOWS 
        //-------------------------------------------------------------------------------------------------------               
        glViewport(0, 0, (GLsizei)viewWidth, (GLsizei)viewHeight);
        LoadIdentity(projectionMatrix);
        PerspectiveMatrix(projectionMatrix, fieldOfView+14, (GLfloat)viewWidth / (GLfloat)viewHeight, adjustNearFar_CAMERA[0],  adjustNearFar_CAMERA[1]);
        //-------------------------------------------------------------------------------------------------------  
        Rotate(projectionMatrix, 0.0, 0.0, 1.0, -90.0);//_____FOR_iOS_LANDSCAPE_VIEW 
        //-------------------------------------------------------------------------------------------------------          
    #endif                  //__THE_+14_CORRECTS_FOR_DIFFERENCE_IN_iOS_vs._WINDOWS 
    //=======================================================================================================



    //=================================================================================
 

    //========================================================================= 

    //========================================================================= 
        shaderNumber = 15; 
        #include "_MODEL_FOLDERS_/o11/o11_RENDER.cpp"  
    //========================================================================= 
        shaderNumber = 15; 
        #include "_MODEL_FOLDERS_\o18\o18_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o17\o17_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o19\o19_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o12\o12_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o10\o10_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o1\o1_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o21\o21_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o8_B\o8_B_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o8_A\o8_A_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o5\o5_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o15\o15_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o16\o16_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o6\o6_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o14\o14_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o13\o13_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o7\o7_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o20\o20_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o9\o9_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o2\o2_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o4\o4_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o3\o3_RENDER.cpp"  
    //========================================================================= 
    Cube_isActive = true;
    #include "_MODEL_FOLDERS_\Cube\Cube_RENDER.cpp"
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o21\rocks_o21_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o15\rocks_o15_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o17\rocks_o17_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o18\rocks_o18_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o19\rocks_o19_RENDER.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o20\rocks_o20_RENDER.cpp"  


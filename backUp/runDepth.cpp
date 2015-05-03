//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#ifdef WIN32
        //----------------------------------------------------------------
        glClear (GL_DEPTH_BUFFER_BIT);
        glViewport(1, 1, (GLsizei)(viewWidth) * resize_SHADOW_FBO - 2, (GLsizei)(viewHeight) * resize_SHADOW_FBO - 2);
        //----------------------------------------------------------------

      LoadIdentity(shadowProjectionMatrix);
      PerspectiveMatrix(shadowProjectionMatrix, fieldOfView_SHADOW, (GLfloat)viewWidth /(GLfloat)viewHeight,  adjustNearFar_LIGHT[0],  adjustNearFar_LIGHT[1]);

//float aspectRatio = viewWidth/viewHeight;
//LoadIdentity(light_projection);
//mtxOrtho(light_projection, -4*aspectRatio, 4*aspectRatio , -4, 4, 2, 50);




/*
        //----------------------------------------------------------------
        glClear (GL_DEPTH_BUFFER_BIT);
        glViewport(1, 1, (2048)-2, (2048)-2);
        //----------------------------------------------------------------

        LoadIdentity(Light_Projection);
        PerspectiveMatrix(Light_Projection, fieldOfView_SHADOW, 2048 / 2048,  adjustNearFar[0],  adjustNearFar[1]);
*/
#endif
   
#ifdef   __APPLE__     
        //----------------------------------------------------------------
        glClear (GL_DEPTH_BUFFER_BIT);
        glViewport(1, 1, 2000 - 2, 1000 - 2);
        //----------------------------------------------------------------
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); 
        LoadIdentity(shadowProjectionMatrix);
        PerspectiveMatrix(shadowProjectionMatrix, fieldOfView_SHADOW, 2000 / 1000,  adjustNearFar_LIGHT[0],  adjustNearFar_LIGHT[1]);
#endif          
      

        //====================================================================================    

shaderNumber = 11;      
setupTransforms_Shadows();         

                                                            


    //========================================================================= 
/*


    //========================================================================= 
    #include "_MODEL_FOLDERS_\o11\o11_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o18\o18_SHADOW_0.cpp"  


    //========================================================================= 
    #include "_MODEL_FOLDERS_\o17\o17_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o19\o19_SHADOW_0.cpp"  


    //========================================================================= 
    #include "_MODEL_FOLDERS_\o12\o12_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o10\o10_SHADOW_0.cpp"  




    //========================================================================= 
    #include "_MODEL_FOLDERS_\o1\o1_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o21\o21_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o8_B\o8_B_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o8_A\o8_A_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o5\o5_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o15\o15_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o16\o16_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o6\o6_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o14\o14_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o13\o13_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o7\o7_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o20\o20_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o9\o9_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o2\o2_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o4\o4_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o3\o3_SHADOW_0.cpp"  
*/


    //========================================================================= 
    //#include "_MODEL_FOLDERS_\Cube\Cube_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\domeTree_x4\domeTree_x4_SHADOW_0.cpp"
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o21\rocks_o21_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o15\rocks_o15_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o17\rocks_o17_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o18\rocks_o18_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o19\rocks_o19_SHADOW_0.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o20\rocks_o20_SHADOW_0.cpp"  


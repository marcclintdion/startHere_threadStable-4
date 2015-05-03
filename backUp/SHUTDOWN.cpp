//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-


    //====================================================================================
    //#include "_SHADERS/drawMainColor_FBO/drawMainColor_FBO_SHUTDOWN.cpp"
    //====================================================================================
    #include "_SHADERS/drawMainColor_PRIMARY_FBO/drawMainColor_PRIMARY_FBO_SHUTDOWN.cpp"
    //====================================================================================
    //#include "_SHADERS/hardEdgeShadow_FBO/hardEdgeShadow_FBO_SHUTDOWN.cpp"
    //==================================================================================== 
    #include "_SHADERS/generic_FBO/generic_FBO_SHUTDOWN.cpp"
    //==================================================================================== 
    
    //####################################################################################    
   
    //====================================================================================     
    #include "_SHADERS/finalComposite/finalComposite_SHADER_SHUTDOWN.cpp"
    //====================================================================================        
    #include "_SHADERS/SHADOWS/shadows_32bit_Stride_SHADER_SHUTDOWN.cpp"
    //====================================================================================      
    //#include "_SHADERS/gaussianBlur_9x/gaussianBlur_9x_SHADER_SHUTDOWN.cpp"
    //====================================================================================
    #include "_SHADERS/copyFBO/copyFBO_SHADER_SHUTDOWN.cpp"
    //==================================================================================== 
    #include "_SHADERS/PowerVR_blur/PowerVR_blur_SHADER_SHUTDOWN.cpp"
   //====================================================================================        

    //#include "_SHADERS/softDiffuse_SHADER/softDiffuse_SHADER_SHUTDOWN.cpp"
    //====================================================================================        
    #include "_SHADERS/mixShaders/bronzePlastic/bronzePlastic_SHADER_END.cpp"
    //====================================================================================        
    #include "_SHADERS/mixShaders/stoneBronze/stoneBronze_SHADER_END.cpp"
    if(stone_Fresnel_TEX  != 0)
    {
        glDeleteTextures(1, &stone_Fresnel_TEX); //-> I_PUT_THE_TEXTURE_HERE_BECAUSE_IT_IS_BEING_USED_BY_THIS_FRESNEL_ALGORITHM
        stone_Fresnel_TEX  = 0;
    }
    //====================================================================================
    #include "_SHADERS/baseColor/baseColor_SHADER_END.cpp"
    //====================================================================================
    #include "_SHADERS/baseColor_x4tex/baseColor_x4tex_SHADER_END.cpp"
    //====================================================================================    
    
    
    //####################################################################################
    //====================================================================================
    #include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_SHUTDOWN.cpp"
    //====================================================================================
    //-------------------------------------------------------------------------
    //=========================================================================



    //========================================================================= 
    #include "_MODEL_FOLDERS_\o11\o11_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o18\o18_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o17\o17_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o19\o19_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o12\o12_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o10\o10_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o1\o1_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o21\o21_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o8_B\o8_B_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o8_A\o8_A_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o5\o5_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o15\o15_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o16\o16_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o6\o6_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o14\o14_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o13\o13_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o7\o7_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o20\o20_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o9\o9_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o2\o2_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o4\o4_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\o3\o3_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\Cube\Cube_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\domeTree_x4\domeTree_x4_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o21\rocks_o21_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o15\rocks_o15_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o17\rocks_o17_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o18\rocks_o18_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o19\rocks_o19_SHUTDOWN.cpp"  
    //========================================================================= 
    #include "_MODEL_FOLDERS_\rocks_o20\rocks_o20_SHUTDOWN.cpp"  


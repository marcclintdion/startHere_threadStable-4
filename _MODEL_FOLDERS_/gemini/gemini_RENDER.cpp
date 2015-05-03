    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(gemini_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(gemini_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            gemini_FilePath = "_MODEL_FOLDERS_/gemini/gemini.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_gemini_FromHDtoSystemRAM, 0, NULL);                               
            gemini_isLoaded = true;                                                             
        }                                                                                   
        if(gemini_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_gemini, gemini_COLORMAP, FreeImage_GetWidth(dib_gemini),  FreeImage_GetHeight(dib_gemini) );     
            delete_gemini_FromSystemRAM();                                                      
            gemini_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, gemini_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gemini_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, gemini_POSITION[0] + moveSet[0], 
                                                gemini_POSITION[1] + moveSet[1], 
                                                gemini_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    gemini_ROTATION[0], 
                                                gemini_ROTATION[1], 
                                                gemini_ROTATION[2],  
                                                gemini_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, gemini_ROTATION[0], 
                                                gemini_ROTATION[1], 
                                                gemini_ROTATION[2], 
                                                gemini_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, gemini_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 804, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(gemini_isActive == false && gemini_isLoaded == true)                                         
    {                                                                                       
        if(gemini_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &gemini_COLORMAP);                                              
            gemini_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        gemini_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  

    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(copperEntrance_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(copperEntrance_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            copperEntrance_FilePath = "_MODEL_FOLDERS_/copperEntrance/copperEntrance.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_copperEntrance_FromHDtoSystemRAM, 0, NULL);                               
            copperEntrance_isLoaded = true;                                                             
        }                                                                                   
        if(copperEntrance_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_copperEntrance, copperEntrance_COLORMAP, FreeImage_GetWidth(dib_copperEntrance),  FreeImage_GetHeight(dib_copperEntrance) );     
            delete_copperEntrance_FromSystemRAM();                                                      
            copperEntrance_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, copperEntrance_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, copperEntrance_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, copperEntrance_POSITION[0] + moveSet[0], 
                                                copperEntrance_POSITION[1] + moveSet[1], 
                                                copperEntrance_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    copperEntrance_ROTATION[0], 
                                                copperEntrance_ROTATION[1], 
                                                copperEntrance_ROTATION[2],  
                                                copperEntrance_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, copperEntrance_ROTATION[0], 
                                                copperEntrance_ROTATION[1], 
                                                copperEntrance_ROTATION[2], 
                                                copperEntrance_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, copperEntrance_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 10395, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(copperEntrance_isActive == false && copperEntrance_isLoaded == true)                                         
    {                                                                                       
        if(copperEntrance_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &copperEntrance_COLORMAP);                                              
            copperEntrance_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        copperEntrance_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  

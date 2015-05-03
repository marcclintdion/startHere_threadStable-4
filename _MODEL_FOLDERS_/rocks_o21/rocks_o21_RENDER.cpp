    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(rocks_o21_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(rocks_o21_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            rocks_o21_FilePath = "_MODEL_FOLDERS_/rocks_o21/o21_rocks.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_rocks_o21_FromHDtoSystemRAM, 0, NULL);                               
            rocks_o21_isLoaded = true;                                                             
        }                                                                                   
        if(rocks_o21_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_rocks_o21, rocks_o21_COLORMAP, FreeImage_GetWidth(dib_rocks_o21),  FreeImage_GetHeight(dib_rocks_o21) );     
            delete_rocks_o21_FromSystemRAM();                                                      
            rocks_o21_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, rocks_o21_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rocks_o21_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, rocks_o21_POSITION[0] + moveSet[0], 
                                                rocks_o21_POSITION[1] + moveSet[1], 
                                                rocks_o21_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    rocks_o21_ROTATION[0], 
                                                rocks_o21_ROTATION[1], 
                                                rocks_o21_ROTATION[2],  
                                                rocks_o21_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, rocks_o21_ROTATION[0], 
                                                rocks_o21_ROTATION[1], 
                                                rocks_o21_ROTATION[2], 
                                                rocks_o21_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, rocks_o21_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 3390, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(rocks_o21_isActive == false && rocks_o21_isLoaded == true)                                         
    {                                                                                       
        if(rocks_o21_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &rocks_o21_COLORMAP);                                              
            rocks_o21_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        rocks_o21_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  

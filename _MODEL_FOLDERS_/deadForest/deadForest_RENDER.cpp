    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(deadForest_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(deadForest_isLoaded == false)                                                            
        {                                                                                   
            deadForest_FilePath = "_MODEL_FOLDERS_/deadForest/deadForest.png";                                     
            _beginthread(load_deadForest_FromHDtoSystemRAM, 0, NULL);                               
            deadForest_isLoaded = true;                                                             
        }                                                                                   
        if(deadForest_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_deadForest, deadForest_COLORMAP, FreeImage_GetWidth(dib_deadForest),  FreeImage_GetHeight(dib_deadForest) );     
            delete_deadForest_FromSystemRAM();                                                      
            deadForest_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                              
        //==================================                                              
                setupTransforms_MainColor();                                              
                    //--------------------------                                          
                    glBindBuffer(GL_ARRAY_BUFFER, deadForest_VBO);                                
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, deadForest_INDICES_VBO);                
                    //--------------------------------                                    
                    LoadIdentity(modelWorldMatrix);                                       
                    //--------------------------------------------------------            
                    Translate(modelWorldMatrix, deadForest_POSITION[0] + moveSet[0], 
                                                deadForest_POSITION[1] + moveSet[1], 
                                                deadForest_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------            
                    Rotate(modelWorldMatrix,    deadForest_ROTATION[0], 
                                                deadForest_ROTATION[1], 
                                                deadForest_ROTATION[2],  
                                                deadForest_ROTATION[3]); 
                    //--------------------------------------------------------            
                    LoadIdentity(modelRotationMatrix);                                    
                    //--------------------------------------------------------            
                    Rotate(modelRotationMatrix, deadForest_ROTATION[0], 
                                                deadForest_ROTATION[1], 
                                                deadForest_ROTATION[2], 
                                                deadForest_ROTATION[3]); 
                //===================================================                     
                SelectShader(shaderNumber);                                               
                //===================================================                     
                    glActiveTexture ( GL_TEXTURE0 );                                      
                    glBindTexture(GL_TEXTURE_2D, deadForest_NORMALMAP);                           
                    //------------                                                        
                    glActiveTexture (GL_TEXTURE1);                                        
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                   
                    //------------                                                        
                    glActiveTexture (GL_TEXTURE2);                                        
                    glBindTexture(GL_TEXTURE_2D, deadForest_COLORMAP);                            
                    //--------------                                                      
                    glActiveTexture (GL_TEXTURE3);                                        
                    glBindTexture(GL_TEXTURE_2D, deadForest_MASK0MAP);                            
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 7485, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(deadForest_isActive == false && deadForest_isLoaded == true)                                         
    {                                                                                       
        if(deadForest_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &deadForest_COLORMAP);                                              
            deadForest_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        deadForest_isLoaded = false;                                                                
    }                                                                                       

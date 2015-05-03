    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o14_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o14_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o14_FilePath = "_MODEL_FOLDERS_/o14/o14.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o14_FromHDtoSystemRAM, 0, NULL);                               
            o14_isLoaded = true;                                                             
        }                                                                                   
        if(o14_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o14, o14_COLORMAP, FreeImage_GetWidth(dib_o14),  FreeImage_GetHeight(dib_o14) );     
            delete_o14_FromSystemRAM();                                                      
            o14_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o14_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o14_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o14_POSITION[0] + moveSet[0], 
                                                o14_POSITION[1] + moveSet[1], 
                                                o14_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o14_ROTATION[0], 
                                                o14_ROTATION[1], 
                                                o14_ROTATION[2],  
                                                o14_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o14_ROTATION[0], 
                                                o14_ROTATION[1], 
                                                o14_ROTATION[2], 
                                                o14_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o14_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 19368, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o14_isActive == false && o14_isLoaded == true)                                         
    {                                                                                       
        if(o14_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o14_COLORMAP);                                              
            o14_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o14_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  

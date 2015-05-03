    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o21_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o21_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o21_FilePath = "_MODEL_FOLDERS_/o21/o21.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o21_FromHDtoSystemRAM, 0, NULL);                               
            o21_isLoaded = true;                                                             
        }                                                                                   
        if(o21_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o21, o21_COLORMAP, FreeImage_GetWidth(dib_o21),  FreeImage_GetHeight(dib_o21) );     
            delete_o21_FromSystemRAM();                                                      
            o21_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o21_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o21_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o21_POSITION[0] + moveSet[0], 
                                                o21_POSITION[1] + moveSet[1], 
                                                o21_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o21_ROTATION[0], 
                                                o21_ROTATION[1], 
                                                o21_ROTATION[2],  
                                                o21_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o21_ROTATION[0], 
                                                o21_ROTATION[1], 
                                                o21_ROTATION[2], 
                                                o21_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o21_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 34815, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o21_isActive == false && o21_isLoaded == true)                                         
    {                                                                                       
        if(o21_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o21_COLORMAP);                                              
            o21_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o21_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  

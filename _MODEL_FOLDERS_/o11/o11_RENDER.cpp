    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o11_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o11_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o11_FilePath = "_MODEL_FOLDERS_/o11/o11.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o11_FromHDtoSystemRAM, 0, NULL);                               
            o11_isLoaded = true;                                                             
        }                                                                                   
        if(o11_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o11, o11_COLORMAP, FreeImage_GetWidth(dib_o11),  FreeImage_GetHeight(dib_o11) );     
            delete_o11_FromSystemRAM();                                                      
            o11_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o11_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o11_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o11_POSITION[0] + moveSet[0], 
                                                o11_POSITION[1] + moveSet[1], 
                                                o11_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o11_ROTATION[0], 
                                                o11_ROTATION[1], 
                                                o11_ROTATION[2],  
                                                o11_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o11_ROTATION[0], 
                                                o11_ROTATION[1], 
                                                o11_ROTATION[2], 
                                                o11_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o11_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 34866, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o11_isActive == false && o11_isLoaded == true)                                         
    {                                                                                       
        if(o11_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o11_COLORMAP);                                              
            o11_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o11_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  

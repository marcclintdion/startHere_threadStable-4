    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o5_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o5_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o5_FilePath = "_MODEL_FOLDERS_/o5/o5.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o5_FromHDtoSystemRAM, 0, NULL);                               
            o5_isLoaded = true;                                                             
        }                                                                                   
        if(o5_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o5, o5_COLORMAP, FreeImage_GetWidth(dib_o5),  FreeImage_GetHeight(dib_o5) );     
            delete_o5_FromSystemRAM();                                                      
            o5_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o5_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o5_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o5_POSITION[0] + moveSet[0], 
                                                o5_POSITION[1] + moveSet[1], 
                                                o5_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o5_ROTATION[0], 
                                                o5_ROTATION[1], 
                                                o5_ROTATION[2],  
                                                o5_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o5_ROTATION[0], 
                                                o5_ROTATION[1], 
                                                o5_ROTATION[2], 
                                                o5_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o5_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 35661, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o5_isActive == false && o5_isLoaded == true)                                         
    {                                                                                       
        if(o5_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o5_COLORMAP);                                              
            o5_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o5_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  

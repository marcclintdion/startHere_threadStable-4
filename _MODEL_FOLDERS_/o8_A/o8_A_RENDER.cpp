    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o8_A_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o8_A_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o8_A_FilePath = "_MODEL_FOLDERS_/o8_A/o8_A.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o8_A_FromHDtoSystemRAM, 0, NULL);                               
            o8_A_isLoaded = true;                                                             
        }                                                                                   
        if(o8_A_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o8_A, o8_A_COLORMAP, FreeImage_GetWidth(dib_o8_A),  FreeImage_GetHeight(dib_o8_A) );     
            delete_o8_A_FromSystemRAM();                                                      
            o8_A_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o8_A_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o8_A_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o8_A_POSITION[0] + moveSet[0], 
                                                o8_A_POSITION[1] + moveSet[1], 
                                                o8_A_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o8_A_ROTATION[0], 
                                                o8_A_ROTATION[1], 
                                                o8_A_ROTATION[2],  
                                                o8_A_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o8_A_ROTATION[0], 
                                                o8_A_ROTATION[1], 
                                                o8_A_ROTATION[2], 
                                                o8_A_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o8_A_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 16089, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o8_A_isActive == false && o8_A_isLoaded == true)                                         
    {                                                                                       
        if(o8_A_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o8_A_COLORMAP);                                              
            o8_A_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o8_A_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  

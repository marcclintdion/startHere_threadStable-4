    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o16_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o16_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o16_FilePath = "_MODEL_FOLDERS_/o16/o16.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o16_FromHDtoSystemRAM, 0, NULL);                               
            o16_isLoaded = true;                                                             
        }                                                                                   
        if(o16_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o16, o16_COLORMAP, FreeImage_GetWidth(dib_o16),  FreeImage_GetHeight(dib_o16) );     
            delete_o16_FromSystemRAM();                                                      
            o16_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o16_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o16_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o16_POSITION[0] + moveSet[0], 
                                                o16_POSITION[1] + moveSet[1], 
                                                o16_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o16_ROTATION[0], 
                                                o16_ROTATION[1], 
                                                o16_ROTATION[2],  
                                                o16_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o16_ROTATION[0], 
                                                o16_ROTATION[1], 
                                                o16_ROTATION[2], 
                                                o16_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o16_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 33972, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o16_isActive == false && o16_isLoaded == true)                                         
    {                                                                                       
        if(o16_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o16_COLORMAP);                                              
            o16_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o16_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  

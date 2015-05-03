    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o19_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o19_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o19_FilePath = "_MODEL_FOLDERS_/o19/o19.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o19_FromHDtoSystemRAM, 0, NULL);                               
            o19_isLoaded = true;                                                             
        }                                                                                   
        if(o19_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o19, o19_COLORMAP, FreeImage_GetWidth(dib_o19),  FreeImage_GetHeight(dib_o19) );     
            delete_o19_FromSystemRAM();                                                      
            o19_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o19_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o19_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o19_POSITION[0] + moveSet[0], 
                                                o19_POSITION[1] + moveSet[1], 
                                                o19_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o19_ROTATION[0], 
                                                o19_ROTATION[1], 
                                                o19_ROTATION[2],  
                                                o19_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o19_ROTATION[0], 
                                                o19_ROTATION[1], 
                                                o19_ROTATION[2], 
                                                o19_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o19_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 35196, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o19_isActive == false && o19_isLoaded == true)                                         
    {                                                                                       
        if(o19_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o19_COLORMAP);                                              
            o19_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o19_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  

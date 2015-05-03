    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o13_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o13_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o13_FilePath = "_MODEL_FOLDERS_/o13/o13.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o13_FromHDtoSystemRAM, 0, NULL);                               
            o13_isLoaded = true;                                                             
        }                                                                                   
        if(o13_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o13, o13_COLORMAP, FreeImage_GetWidth(dib_o13),  FreeImage_GetHeight(dib_o13) );     
            delete_o13_FromSystemRAM();                                                      
            o13_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o13_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o13_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o13_POSITION[0] + moveSet[0], 
                                                o13_POSITION[1] + moveSet[1], 
                                                o13_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o13_ROTATION[0], 
                                                o13_ROTATION[1], 
                                                o13_ROTATION[2],  
                                                o13_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o13_ROTATION[0], 
                                                o13_ROTATION[1], 
                                                o13_ROTATION[2], 
                                                o13_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o13_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 27012, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o13_isActive == false && o13_isLoaded == true)                                         
    {                                                                                       
        if(o13_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o13_COLORMAP);                                              
            o13_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o13_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  

    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o18_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o18_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o18_FilePath = "_MODEL_FOLDERS_/o18/o18.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o18_FromHDtoSystemRAM, 0, NULL);                               
            o18_isLoaded = true;                                                             
        }                                                                                   
        if(o18_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o18, o18_COLORMAP, FreeImage_GetWidth(dib_o18),  FreeImage_GetHeight(dib_o18) );     
            delete_o18_FromSystemRAM();                                                      
            o18_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o18_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o18_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o18_POSITION[0] + moveSet[0], 
                                                o18_POSITION[1] + moveSet[1], 
                                                o18_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o18_ROTATION[0], 
                                                o18_ROTATION[1], 
                                                o18_ROTATION[2],  
                                                o18_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o18_ROTATION[0], 
                                                o18_ROTATION[1], 
                                                o18_ROTATION[2], 
                                                o18_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o18_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 34023, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o18_isActive == false && o18_isLoaded == true)                                         
    {                                                                                       
        if(o18_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o18_COLORMAP);                                              
            o18_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o18_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  

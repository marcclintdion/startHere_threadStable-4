    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o9_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o9_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o9_FilePath = "_MODEL_FOLDERS_/o9/o9.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o9_FromHDtoSystemRAM, 0, NULL);                               
            o9_isLoaded = true;                                                             
        }                                                                                   
        if(o9_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o9, o9_COLORMAP, FreeImage_GetWidth(dib_o9),  FreeImage_GetHeight(dib_o9) );     
            delete_o9_FromSystemRAM();                                                      
            o9_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o9_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o9_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o9_POSITION[0] + moveSet[0], 
                                                o9_POSITION[1] + moveSet[1], 
                                                o9_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o9_ROTATION[0], 
                                                o9_ROTATION[1], 
                                                o9_ROTATION[2],  
                                                o9_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o9_ROTATION[0], 
                                                o9_ROTATION[1], 
                                                o9_ROTATION[2], 
                                                o9_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o9_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 37329, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o9_isActive == false && o9_isLoaded == true)                                         
    {                                                                                       
        if(o9_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o9_COLORMAP);                                              
            o9_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o9_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  

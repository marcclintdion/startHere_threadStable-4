    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o3_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o3_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o3_FilePath = "_MODEL_FOLDERS_/o3/o3.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o3_FromHDtoSystemRAM, 0, NULL);                               
            o3_isLoaded = true;                                                             
        }                                                                                   
        if(o3_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o3, o3_COLORMAP, FreeImage_GetWidth(dib_o3),  FreeImage_GetHeight(dib_o3) );     
            delete_o3_FromSystemRAM();                                                      
            o3_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o3_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o3_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o3_POSITION[0] + moveSet[0], 
                                                o3_POSITION[1] + moveSet[1], 
                                                o3_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o3_ROTATION[0], 
                                                o3_ROTATION[1], 
                                                o3_ROTATION[2],  
                                                o3_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o3_ROTATION[0], 
                                                o3_ROTATION[1], 
                                                o3_ROTATION[2], 
                                                o3_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o3_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 37767, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o3_isActive == false && o3_isLoaded == true)                                         
    {                                                                                       
        if(o3_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o3_COLORMAP);                                              
            o3_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o3_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  

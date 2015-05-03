    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o2_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o2_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o2_FilePath = "_MODEL_FOLDERS_/o2/o2.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o2_FromHDtoSystemRAM, 0, NULL);                               
            o2_isLoaded = true;                                                             
        }                                                                                   
        if(o2_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o2, o2_COLORMAP, FreeImage_GetWidth(dib_o2),  FreeImage_GetHeight(dib_o2) );     
            delete_o2_FromSystemRAM();                                                      
            o2_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o2_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o2_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o2_POSITION[0] + moveSet[0], 
                                                o2_POSITION[1] + moveSet[1], 
                                                o2_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o2_ROTATION[0], 
                                                o2_ROTATION[1], 
                                                o2_ROTATION[2],  
                                                o2_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o2_ROTATION[0], 
                                                o2_ROTATION[1], 
                                                o2_ROTATION[2], 
                                                o2_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o2_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 34014, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o2_isActive == false && o2_isLoaded == true)                                         
    {                                                                                       
        if(o2_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o2_COLORMAP);                                              
            o2_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o2_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  

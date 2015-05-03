    //==========================================                                            
    //-----------LOAD_ASSETS--------------------                                            
    //======================                                                                
    if(o6_isActive == true)                                                                 
    {                                                                                       
        //-------------_CREATE_ASSETS-----------------                                      
        if(o6_isLoaded == false && MAX_THREADS < 3)                                         
        {                                                                                   
            o6_FilePath = "_MODEL_FOLDERS_/o6/o6.png";                                    
            MAX_THREADS += 1;                                                               
            _beginthread(load_o6_FromHDtoSystemRAM, 0, NULL);                               
            o6_isLoaded = true;                                                             
        }                                                                                   
        if(o6_isLoadedFromDriveAndWaiting == true)                                          
        {                                                                                   
            ConfigureAndLoadTexture(pixels_o6, o6_COLORMAP, FreeImage_GetWidth(dib_o6),  FreeImage_GetHeight(dib_o6) );     
            delete_o6_FromSystemRAM();                                                      
            o6_isLoadedFromDriveAndWaiting = false;                                         
        }                                                                                   
        //----------------------------------------------------------                        
        //=================================================================================================================   
        //-----------RENDER_ASSETS----------                                                
        //==================================                                                
                setupTransforms_MainColor();                                                
                    //--------------------------                                            
                    glBindBuffer(GL_ARRAY_BUFFER, o6_VBO);                                  
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, o6_INDICES_VBO);                  
                    //--------------------------------                                      
                    LoadIdentity(modelWorldMatrix);                                         
                    //--------------------------------------------------------              
                    Translate(modelWorldMatrix, o6_POSITION[0] + moveSet[0], 
                                                o6_POSITION[1] + moveSet[1], 
                                                o6_POSITION[2] + moveSet[2]); 
                    //--------------------------------------------------------              
                    Rotate(modelWorldMatrix,    o6_ROTATION[0], 
                                                o6_ROTATION[1], 
                                                o6_ROTATION[2],  
                                                o6_ROTATION[3]); 
                    //--------------------------------------------------------              
                    LoadIdentity(modelRotationMatrix);                                      
                    //--------------------------------------------------------              
                    Rotate(modelRotationMatrix, o6_ROTATION[0], 
                                                o6_ROTATION[1], 
                                                o6_ROTATION[2], 
                                                o6_ROTATION[3]); 
                //===================================================                       
                SelectShader(shaderNumber);                                                 
                //===================================================                       
                    glActiveTexture (GL_TEXTURE0);                                          
                    glBindTexture(GL_TEXTURE_2D, o6_COLORMAP);                              
                    //------------                                                          
                    glActiveTexture (GL_TEXTURE1);                                          
                    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                     
                    //------------                                                          
                    //-----------------------------------------------------                 
                    glDrawElements(GL_TRIANGLES, 36999, GL_UNSIGNED_INT, 0);                   

    }                                                                                       
    //==============================================================                        
    //---------------DELETE_ASSETS------------------------                                  
    //====================================================                                  
    if(o6_isActive == false && o6_isLoaded == true)                                         
    {                                                                                       
        if(o6_COLORMAP  != 0)                                                               
        {                                                                                   
            glDeleteTextures(1, &o6_COLORMAP);                                              
            o6_COLORMAP = 0;                                                                
        }                                                                                   
        //------------------                                                                
        o6_isLoaded = false;                                                                
    }                                                                                       
    //====================================================                                  


        //--------------------------------------------     
        attribute       vec4   position;                                                                                            
        attribute       vec2   uv0;                                                                                                 
        //--------------------------------------------   
        uniform         mat4   projectionMatrix;                                                                                        
        uniform         mat4   modelViewMatrix;                                                                                         
        //======================================
        varying    vec2   uv0_PASS;                                                                                            
        //======================================   

    //===============================================================================================
    
     void main()                                                                                                                    
     {                                                                                                                              
                                                                   
         //-------------------------------------------------------------------------------
         uv0_PASS                =  uv0;                                                                                            
         //===============================================================================
         gl_Position             =  projectionMatrix * position;                                                                    
    
     }  

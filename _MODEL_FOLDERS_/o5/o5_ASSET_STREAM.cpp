#ifdef WIN32 
void load_o5_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o5 = FreeImage_GetFileType(o5_FilePath, 0);                       
    dib_o5   = FreeImage_Load(fifmt_o5, o5_FilePath, 0);                    
    temp_o5  = dib_o5;                                                      
    dib_o5   = FreeImage_ConvertTo32Bits(temp_o5);                          
    FreeImage_Unload(temp_o5);                                            

    if( dib_o5 != NULL )                                                    
    {                                                                       
        pixels_o5 = (BYTE*)FreeImage_GetBits(dib_o5);                       
    }                                                                     

    o5_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o5_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o5 != NULL )                                                    
    {                                                                       
        free(pixels_o5);                                                    
        FreeImage_Unload(dib_o5);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      

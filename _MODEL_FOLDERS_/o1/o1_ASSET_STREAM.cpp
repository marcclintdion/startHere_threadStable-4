#ifdef WIN32 
void load_o1_FromHDtoSystemRAM(void*) 
{                                                                           
    fifmt_o1 = FreeImage_GetFileType(o1_FilePath, 0);                       
    dib_o1   = FreeImage_Load(fifmt_o1, o1_FilePath, 0);                    
    temp_o1  = dib_o1;                                                      
    dib_o1   = FreeImage_ConvertTo32Bits(temp_o1);                          
    FreeImage_Unload(temp_o1);                                            

    if( dib_o1 != NULL )                                                    
    {                                                                       
        pixels_o1 = (BYTE*)FreeImage_GetBits(dib_o1);                       
    }                                                                     

    o1_isLoadedFromDriveAndWaiting = true;                                  
    //---------------------                                                 
    if(MAX_THREADS > 0)                                                     
    {                                                                       
         MAX_THREADS -= 1;                                                  
    }                                                                       
    //---------------------                                                 
    _endthread();                                                           
}                                                                           
//----------------------------------------------------------                
void delete_o1_FromSystemRAM(void)                                          
{                                                                           
    if( dib_o1 != NULL )                                                    
    {                                                                       
        free(pixels_o1);                                                    
        FreeImage_Unload(dib_o1);                                           
    }                                                                     

}                                                                           
//==========================================================                
#endif                                                                      

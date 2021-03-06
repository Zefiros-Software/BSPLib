#Interfaces

```cpp
void BSPLib::Sync()              // (1) Modern
void BSPLib::Classic::Sync()     // (2) Classic
void bsp_sync()                  // (3) BSP
```

Synchronises all threads and communications. This marks the end of a computation super step, 
and each processor can handle its own computations between the super steps. At the end (and not earlier)
of the super step in the synchronisation point, the communication is handled. All threads have queued
their desired communications before this point, and the queues will now be handled here. The 
synchronisation point also ensures all threads are synchronised, and functions as a barrier.

#Pre-Conditions
* [`BSPLib::Classic::Begin()`](../logic/begin.md) has been called.

#Post-Conditions
* All threads have completed this superstep.
* Tagsize has been synchronized and is available in the next superstep.
* Get requests have been processed, updated data is available in the next superstep.
* Pop requests have been processed, registers will be unavailable in the next superstep.
* Put requests have been processed, updated data is available in the next superstep.
* Buffers for the put requests have been cleared.
* Push requests have been processed, registers will be available in the next superstep.

1. This is interface one should choose to use, and is semantically the same as the other interfaces.
2. Classic BSP function, this is the interface one should prefer to use over the old BSP interface.
3. Legacy BSP function, this interface is included for backwards compatibility with other BSP libraries.
     
#Examples

###(1) Modern

```cpp
void main( int32_t, const char ** )
{
    const uint32_t nProcs = BSPLib::NProcs();
    // Waits for all threads to print the first line, 
    // before printing the second line.
      BSPLib::Execute( []
    {            
        std::cout << "Thread " <<  BSPLib::ProcId() 
                  << " waiting on barrier 1" << std::endl;
        
        // Wait for all threads to print
        BSPLib::Sync();
    
        std::cout << "Thread " <<  BSPLib::ProcId() 
                  << " waiting on barrier 2" << std::endl;
                  
        BSPLib::Sync();
    }, nProcs );
}
```

###(2) Classic

```cpp
void main( int32_t, const char ** )
{
    const uint32_t nProcs = BSPLib::NProcs();
    // Waits for all threads to print the first line, 
    // before printing the second line.
      BSPLib::Execute( []
    {            
        std::cout << "Thread " <<  BSPLib::Classic::ProcId() 
                  << " waiting on barrier 1" << std::endl;
        
        // Wait for all threads to print
        BSPLib::Classic::Sync();
    
        std::cout << "Thread " <<  BSPLib::Classic::ProcId() 
                  << " waiting on barrier 2" << std::endl;
                  
        BSPLib::Classic::Sync();
    }, nProcs );
}
```

###(3) BSP

```cpp
void main( int32_t, const char ** )
{
    const uint32_t nProcs = bsp_nprocs();
    // Waits for all threads to print the first line, 
    // before printing the second line.
      BSPLib::Execute( []
    {            
        std::cout << "Thread " <<  bsp_pid() 
                  << " waiting on barrier 1" << std::endl;
        
        // Wait for all threads to print
        bsp_sync();
    
        std::cout << "Thread " <<  bsp_pid() 
                  << " waiting on barrier 2" << std::endl;
        bsp_sync();
    }, nProcs );
}
```
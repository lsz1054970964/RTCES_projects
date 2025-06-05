#include "critical_section.h"
#include "tasks.h"
#include <stdio.h>

CriticalSectionSemaphore usPrioritySemaphoreInit(void **params, int number_of_tasks) {
    // PeriodicTaskParams **task_params = (PeriodicTaskParams **)params;
    CriticalSectionSemaphore cs_semaphore;
    cs_semaphore.semaphore = xSemaphoreCreateBinary();
    if (cs_semaphore.semaphore == NULL) {
        printf("Semaphore create failed!\n");
    }

    UBaseType_t maxPriority = 0;
    for (int i = 0; i < number_of_tasks; i++) {
        PeriodicTaskParams *taskParam = (PeriodicTaskParams *)params[i];

    
        UBaseType_t priority = taskParam->priority;
        if (priority > maxPriority) {
            maxPriority = priority;
            printf("currenPpriority is :%d\n", maxPriority);
        }
    }
  

    printf("maxPriority is :%d\n", maxPriority);
    cs_semaphore.ceilingPriority = maxPriority + 1;


    xSemaphoreGive(cs_semaphore.semaphore);
    return cs_semaphore;
}

void usPrioritySemaphoreWait(CriticalSectionSemaphore *cs_semaphore) {
    xSemaphoreTake(cs_semaphore->semaphore, portMAX_DELAY);
    TaskHandle_t currentHandle = xTaskGetCurrentTaskHandle();
    cs_semaphore->ownerHandle = currentHandle;
    UBaseType_t currentPriority = uxTaskPriorityGet(currentHandle);
    cs_semaphore->ownerOriginalPriority = currentPriority;
    vTaskPrioritySet(currentHandle, cs_semaphore->ceilingPriority);
}

void usPrioritySemaphoreSignal(CriticalSectionSemaphore *cs_semaphore) {
    if (cs_semaphore->ownerHandle != NULL) {
        vTaskPrioritySet(cs_semaphore->ownerHandle, cs_semaphore->ownerOriginalPriority);
    }
    xSemaphoreGive(cs_semaphore->semaphore);
    cs_semaphore->ownerHandle = NULL;
    cs_semaphore->ownerOriginalPriority = 0;
}

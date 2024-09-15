you need to edit ../drivers/ctr_k1/ctr_k1.c

return RAW values as RMS

results[i].avg = results[i].avg / MAX_SAMPLE_COUNT;
// results[i].rms = sqrtf(results[i].rms / MAX_SAMPLE_COUNT);
results[i].rms = raw_avg[i];

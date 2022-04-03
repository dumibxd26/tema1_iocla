typedef struct head {
	unsigned char type;
	unsigned int len;
} head;

typedef struct data_structure {
	head *header;
	void *data;
} data_structure;

/**
 * @brief Data structure used to store an entry's information
 * 
 */
typedef struct ds_info {

	char *money_from;

	union {
		struct {
			int8_t first_bill;
			int8_t second_bill;
		} one;
		struct {
			int16_t first_bill;
			int32_t second_bill;
		} two;
		struct {
			int32_t first_bill;
			int32_t second_bill;
		} three;

	} type;

	
	char   *money_to;
} ds_info;

#ifndef ADD_H
#define ADD_H

public class dynObjectList {

public:
	dynObjectList();
	void add(dynObject obj);
	bool remove(dynObject obj);
private:
	int length, max;
	dynObject *objArray;

};
dynObjectList::dynObjectList() {

	objArray = new dynObject[500];
	length = 0;
	max = 500;

}

void dynObjectList::add(dynObject obj) {

	if (length >= max) {

		dynObject *tempObjArray = new dynObject[max * 2];
		for(int i = 0; i < max; i++)
			tempObjArray[i] = objArray[i];
		objArray = tempObjArray;
		max *= 2;

	}
	objArray[length] = obj;
	length++;

}

bool dynObjectList::remove(dynObject obj) {

	for(int i = 0; i < length; i++) {

		if (objArray[i].id == obj.id) {

			for(int j = i; j < length; j++) {

				if (j < length - 1)
					objArray[j] = objArray[j + 1];
				else
					objArray[j] = void;

			}
			length--;
			if (length < max / 2 && max > 500) {
				
				dynObject *tempObjArray = new void[max / 2];
				for(int i = 0; i < length; i++)
					tempObjArray[i] = objArray[i];
				objArray = tempObjArray;
				max /= 2;

			}
			return true;

		}

	}
	return false;

}

#endif
import { TestBed } from '@angular/core/testing';

import { ObjectDectectionService } from './object-dectection.service';

describe('ObjectDectectionService', () => {
  let service: ObjectDectectionService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(ObjectDectectionService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});

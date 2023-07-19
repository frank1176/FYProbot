import { ComponentFixture, TestBed } from '@angular/core/testing';

import { UsercallComponent } from './usercall.component';

describe('UsercallComponent', () => {
  let component: UsercallComponent;
  let fixture: ComponentFixture<UsercallComponent>;

  beforeEach(() => {
    TestBed.configureTestingModule({
      declarations: [UsercallComponent]
    });
    fixture = TestBed.createComponent(UsercallComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
